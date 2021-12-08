import java.util.*
import kotlin.math.absoluteValue

fun main() {
  val s = Scanner(System.`in`).useDelimiter("\n")
  var ret = 0
  while(s.hasNext()) {
    val line = s.next().split(" | ")
    val output = line[1].split(" ")
    ret += output.count { it.length in setOf(2, 3, 4, 7) }
  }
  println(ret)
}
