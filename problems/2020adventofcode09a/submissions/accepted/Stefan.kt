import java.math.BigInteger
import java.util.*

fun main() {
  val s = Scanner(System.`in`)

  val buffer = mutableListOf<BigInteger>()
  for (i in 1..25) {
    buffer.add(s.nextBigInteger())
  }

  while (s.hasNext()) {
    val n = s.nextBigInteger()
    if (n !in buffer.indices.flatMap { i -> buffer.indices.map { Pair(i, it) }.filter { it.first != it.second } }
        .map { buffer[it.first] + buffer[it.second] }) {
      println(n)
      return
    }

    buffer.removeAt(0)
    buffer.add(n)
  }
}
