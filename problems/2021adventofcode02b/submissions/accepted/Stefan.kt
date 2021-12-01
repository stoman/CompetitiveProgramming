import java.util.*

fun main() {
  val s = Scanner(System.`in`)

  var depth = 0
  var forward = 0
  var aim = 0
  while (s.hasNext()) {
    when (s.next()) {
      "forward" -> {
        val x = s.nextInt()
        forward += x
        depth += aim * x
      }
      "down" -> aim += s.nextInt()
      "up" -> aim -= s.nextInt()
    }
  }

  println(depth * forward)
}
