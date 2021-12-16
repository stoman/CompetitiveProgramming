import java.math.BigInteger
import java.util.*

abstract class Packet(val version: Int, val type: Int, val bitCount: Int) {
  abstract fun value(): BigInteger
}

class Literal(version: Int, type: Int, bitCount: Int, private val value: Long) : Packet(version, type, bitCount) {
  override fun value(): BigInteger = value.toBigInteger()
}

class Operator(version: Int, type: Int, bitCount: Int, private val subPackets: List<Packet>) : Packet(version, type, bitCount) {
  override fun value(): BigInteger = when(type) {
    0 -> subPackets.sumOf { it.value() }
    1 -> subPackets.map { it.value() }.reduce(BigInteger::times)
    2 -> subPackets.minOf { it.value() }
    3 -> subPackets.maxOf { it.value() }
    5 -> if(subPackets[0].value() > subPackets[1].value()) BigInteger.ONE else BigInteger.ZERO
    6 -> if(subPackets[0].value() < subPackets[1].value()) BigInteger.ONE else BigInteger.ZERO
    7 -> if(subPackets[0].value() == subPackets[1].value()) BigInteger.ONE else BigInteger.ZERO
    else -> throw IllegalStateException("unknown packet type $type")
  }
}

fun Char.toBits(): List<Int> {
  var v = lowercaseChar().digitToInt(16)
  val r = mutableListOf<Int>()
  repeat(4) {
    r.add(v % 2)
    v /= 2
  }
  return r.reversed()
}

fun List<Int>.parseBits(): Long {
  var r = 0L
  for (bit in this) {
    r *= 2
    r += bit
  }
  return r
}

fun List<Int>.parsePacket(): Packet {
  val version = slice(0..2).parseBits().toInt()
  when (val type = slice(3..5).parseBits().toInt()) {
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
  println(packet.value())
}
