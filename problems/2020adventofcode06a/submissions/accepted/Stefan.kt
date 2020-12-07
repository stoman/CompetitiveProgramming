import java.util.*

fun main(args: Array<String>) {
  val s = Scanner(System.`in`).useDelimiter("\n\n")

  var r = 0
  while (s.hasNext()) {
    r+= s.next().toSet().filter { !it.isWhitespace() }.size
  }
  println(r)
}
