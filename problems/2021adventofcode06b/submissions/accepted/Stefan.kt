import java.math.BigInteger
import java.util.*

fun List<BigInteger>.sum(): BigInteger = reduce {a, b -> a+b}

fun main() {
  val s = Scanner(System.`in`).useDelimiter("""[,\s]""")
  val timers = MutableList(9) {BigInteger.ZERO}
  while (s.hasNext()) {
    timers[s.nextInt()]++
  }
  repeat(256) {
    timers.add(BigInteger.ZERO)
    val zero = timers.removeFirst()
    timers[6] += zero
    timers[8] += zero
  }
  println(timers.sum())
}
