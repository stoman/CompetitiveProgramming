import java.math.BigInteger
import java.util.*

fun step1(buffer: List<BigInteger>): BigInteger {
  for (i in 25 until buffer.size) {
    if (buffer[i] !in (i - 25 until i).flatMap { j -> (i - 25 until i).map { Pair(j, it) }.filter { it.first != it.second } }
        .map { buffer[it.first] + buffer[it.second] }) {
      return buffer[i]
    }
  }
  throw RuntimeException("step 1 failed")
}

fun main(args: Array<String>) {
  val s = Scanner(System.`in`)

  val buffer = mutableListOf<BigInteger>()
  while(s.hasNext()) {
    buffer.add(s.nextBigInteger())
  }

  val firstStep = step1(buffer)
  var sum = buffer[0]
  var start = 0
  var end = 0
  while(sum != firstStep) {
    if(sum < firstStep) {
      end++
      sum += buffer[end]
    }
    else {
      sum -= buffer[start]
      start++
    }
  }
  val range = (start..end).map{buffer[it]}
  println(range.min()!! + range.max()!!)
}
