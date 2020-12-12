import java.util.*
import kotlin.math.abs

fun main(args: Array<String>) {
  val s = Scanner(System.`in`)
  var x = 0
  var y = 0
  var wpx = 10
  var wpy = 1
  while (s.hasNext()) {
    val line = s.next()
    val command = line[0]
    val arg = if (line.length > 1) line.drop(1).toInt() else 0
    when (command) {
      'E' -> wpx += arg
      'S' -> wpy -= arg
      'W' -> wpx -= arg
      'N' -> wpy += arg
      'L' -> for(i in 1..arg / 90) {
        val newx = -wpy
        val newy = wpx
        wpx = newx
        wpy = newy
      }
      'R' -> for(i in 1..arg / 90) {
        val newx = wpy
        val newy = -wpx
        wpx = newx
        wpy = newy
      }
      'F' -> {
        x += arg * wpx
        y += arg * wpy
      }
    }
  }
  println(abs(x) + abs(y))
}
