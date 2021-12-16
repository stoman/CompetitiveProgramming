import java.util.*

abstract class Packet(val version: Int, val type: Int, val bitCount: Int) {
  fun versionSum(): Int = version + if(this is Operator) subPackets.sumOf { it.versionSum() } else 0
}

class Literal(version: Int, type: Int, bitCount: Int, val value: Int) : Packet(version, type, bitCount)

class Operator(version: Int, type: Int, bitCount: Int, val subPackets: List<Packet>) : Packet(version, type, bitCount)

fun Char.toBits(): List<Int> {
  var v = lowercaseChar().digitToInt(16)
  val r = mutableListOf<Int>()
  repeat(4) {
    r.add(v % 2)
    v /= 2
  }
  return r.reversed()
}

fun List<Int>.parseBits(): Int {
  var r = 0
  for (bit in this) {
    r *= 2
    r += bit
  }
  return r
}

fun List<Int>.parsePacket(): Packet {
  val version = slice(0..2).parseBits()
  when (val type = slice(3..5).parseBits()) {
    // Literal value.
    4 -> {
      val value = mutableListOf<Int>()
      var i = 1
      do {
        i += 5
        value.addAll(slice(i + 1..i + 4))
      } while (get(i) == 1)
      return Literal(version, type, i + 5, value.parseBits())
    }
    // Operator
    else -> {
      val subPackets = mutableListOf<Packet>()
      var parsedBits = 0
      when(get(6)) {
        0 -> {
          val subLength = slice(7..21).parseBits()
          parsedBits = 22
          while(parsedBits < 22 + subLength) {
            val nextPacket = drop(parsedBits).parsePacket()
            subPackets.add(nextPacket)
            parsedBits += nextPacket.bitCount
          }
        }
        1 -> {
          val subLength = slice(7..17).parseBits()
          parsedBits = 18
          while(subPackets.size < subLength) {
            val nextPacket = drop(parsedBits).parsePacket()
            subPackets.add(nextPacket)
            parsedBits += nextPacket.bitCount
          }
        }
      }
      return Operator(version, type, parsedBits, subPackets)
    }
  }
}

fun main() {
  val packet = Scanner(System.`in`).next().flatMap { it.toBits() }.parsePacket()
  println(packet.versionSum())
}
