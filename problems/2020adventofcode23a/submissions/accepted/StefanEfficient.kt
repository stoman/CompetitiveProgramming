import java.util.*

fun main() {
  val s = Scanner(System.`in`)
  val arr = MutableList(10) { -1 }
  val cups = s.next().map { it.toString().toInt() }
  var last = -1
  for (i in cups) {
    if (last != -1) {
      arr[last] = i
    }
    last = i
  }
  arr[last] = cups[0]

  var active = cups[0]
  repeat(100) {
    val sectionBegin = arr[active]
    val sectionMiddle = arr[sectionBegin]
    val sectionEnd = arr[sectionMiddle]
    arr[active] = arr[sectionEnd]

    var next = active
    do {
      next--
      if (next <= 0) {
        next = arr.size - 1
      }
    } while (next in setOf(sectionBegin, sectionMiddle, sectionEnd))

    arr[sectionEnd] = arr[next]
    arr[next] = sectionBegin

    active = arr[active]
  }

  var i = 1
  do {
    i = arr[i]
    print(i)
  } while (arr[i] != 1)
  println()
}
