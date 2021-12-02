import java.math.BigInteger
import java.util.*

fun main() {
  val s = Scanner(System.`in`)
  val adapters = mutableListOf(0)
  while (s.hasNext()) {
    adapters.add(s.nextInt())
  }
  adapters.add(adapters.maxOrNull()!! + 3)
  adapters.sort()

  val dp = mutableListOf<BigInteger>(BigInteger.ONE)
  for(i in 1 until adapters.size) {
    dp.add(dp.last())
    for(j in 2..3) {
      if(i - j >= 0 && adapters[i-j] >= adapters[i] -3) {
        dp[i] += dp[i-j]
      }
    }
  }

  println(dp.last())
}
