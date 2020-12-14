import java.math.BigInteger
import java.util.*

fun combine(i: BigInteger, mask: String): BigInteger {
  val bin = i.toString(2)
  val value = bin.padStart(mask.length, '0').toList().toMutableList()
  for(j in mask.indices) {
    if(mask[j] != 'X') {
      value[j] = mask[j]
    }
  }
  return value.joinToString("").toBigInteger(2)
}

fun main(args: Array<String>) {
  val s = Scanner(System.`in`).useDelimiter("""]\s=\s|\s=\s|\s|\[""")
  var mask = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
  val mem = mutableMapOf<Int, BigInteger>()
  while (s.hasNext()) {
    val command = s.next()
    if(command == "mask") {
      mask = s.next()
    }
    else {
      val address = s.nextInt()
      mem[address] = combine(s.nextBigInteger(), mask)
    }
  }
  println(mem.values.reduce(BigInteger::plus))
}
