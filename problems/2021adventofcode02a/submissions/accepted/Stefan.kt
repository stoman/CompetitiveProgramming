import java.util.*

fun main() {
  val s = Scanner(System.`in`)

  var depth = 0
  var forward = 0
  while (s.hasNext()) {
    when (s.next()) {
      "forward" -> forward += s.nextInt()
      "down" -> depth += s.nextInt()
      "up" -> depth -= s.nextInt()
    }
  }

  println(depth * forward)
}
