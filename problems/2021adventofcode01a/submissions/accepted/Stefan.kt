import java.util.*

fun main() {
  val s = Scanner(System.`in`)

  var last: Int? = null
  var increases = 0
  while (s.hasNext()) {
    val next = s.nextInt()
    if (last != null && next > last) {
      increases++
    }
    last = next
  }

  println(increases)
}
