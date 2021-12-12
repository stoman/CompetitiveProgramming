import java.util.*
import kotlin.math.max

class Solution {
  private fun gcd(a: Int, b: Int): Int = when {
    a == 0 -> b
    b == 0 -> a
    else -> {
      var h: Int
      var x = a
      var y = b
      do {
        h = x % y
        x = y
        y = h
      } while (y != 0)
      x
    }
  }

  fun nthMagicalNumber(n: Int, a: Int, b: Int): Int {
    val mod = 1000000007
    val g = gcd(a, b)
    val x = a / g
    val y = b / g
    val m = n % (x + y - 1)
    var r = m
    var cx = 0
    var cy = 0
    while (r > 0) {
      when {
        cx + x == cy + y -> {
          cx += x
          cy += y
        }
        cx + x > cy + y -> cy += y
        else -> cx += x
      }
      r--
    }
    val s = max(cx, cy) * g
    return (((n - m).toLong() / (x + y - 1) * x * y * g + s) % mod).toInt()
  }
}

fun main() {
  val s = Scanner(System.`in`)
  println(Solution().nthMagicalNumber(s.nextInt(), s.nextInt(), s.nextInt()))
}