import java.util.*

fun main(args: Array<String>) {
  val s = Scanner(System.`in`).useDelimiter("\n\n")

  var r = 0
  while (s.hasNext()) {
    val ss = Scanner(s.next())
    var intersection = ss.next().toSet()
    while(ss.hasNext()) {
      intersection = intersection.intersect(ss.next().toSet())
    }
    r+= intersection.size
  }
  println(r)
}
