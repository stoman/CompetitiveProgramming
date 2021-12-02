import java.util.*

fun seatId(partitioning: String): Int {
  var r = 0
  var back = 64 * 8
  var right = 4
  for (c in partitioning) {
    when (c) {
      'F' -> back /= 2
      'B' -> {
        r += back
        back /= 2
      }
      'L' -> right /= 2
      'R' -> {
        r += right
        right /= 2
      }
    }
  }
  return r
}

fun main() {
  val s = Scanner(System.`in`)

  var r = 0
  while (s.hasNext()) {
    r = r.coerceAtLeast(seatId(s.next()))
  }
  println(r)
}
