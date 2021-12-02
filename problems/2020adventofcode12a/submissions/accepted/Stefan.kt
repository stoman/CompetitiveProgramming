import java.util.*
import kotlin.math.abs

fun main() {
  val directions = listOf(Pair(1, 0), Pair(0, -1), Pair(-1, 0), Pair(0, 1))
  val s = Scanner(System.`in`)
  var dir = 0
  var x = 0
  var y = 0
  while (s.hasNext()) {
    val line = s.next()
    val command = line[0]
    val arg = if (line.length > 1) line.drop(1).toInt() else 0
    when (command) {
      'E' -> x += arg
      'S' -> y -= arg
      'W' -> x -= arg
      'N' -> y += arg
      'L' -> dir -= arg / 90
      'R' -> dir += arg / 90
      'F' -> {
        x += directions[dir % directions.size].first * arg
        y += directions[dir % directions.size].second * arg
      }
    }
  }
  println(abs(x) + abs(y))
}
