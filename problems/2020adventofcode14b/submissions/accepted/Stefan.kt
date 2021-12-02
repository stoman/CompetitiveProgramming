import java.math.BigInteger
import java.util.*

fun combine(value: List<Char>, mask: String, start: Int = 0): Set<BigInteger> {
  val mutableValue = value.toMutableList()
  for (i in start until mask.length) {
    when (mask[i]) {
      '1' -> mutableValue[i] = mask[i]
      'X' -> {
        mutableValue[i] = '0'
        val setZero = combine(mutableValue, mask, i + 1)
        mutableValue[i] = '1'
        val setOne = combine(mutableValue, mask, i + 1)
        return setZero + setOne
      }
    }
  }
  return setOf(mutableValue.joinToString("").toBigInteger(2))
}

fun combine(i: Int, mask: String): Set<BigInteger> {
  return combine(i.toString(2).padStart(mask.length, '0').toList(), mask)
}

fun main() {
  val s = Scanner(System.`in`).useDelimiter("""]\s=\s|\s=\s|\s|\[""")
  var mask = "".padStart(36, '0')
  val mem = mutableMapOf<BigInteger, BigInteger>()
  while (s.hasNext()) {
    val command = s.next()
    if (command == "mask") {
      mask = s.next()
    } else {
      val address = s.nextInt()
      val value = s.nextBigInteger()
      for (a in combine(address, mask)) {
        mem[a] = value
      }
    }
  }
  println(mem.values.reduce(BigInteger::plus))
}
