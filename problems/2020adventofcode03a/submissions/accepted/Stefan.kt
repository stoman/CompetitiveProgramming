import java.util.*

fun main() {
  val s = Scanner(System.`in`)

  val map: MutableList<List<Boolean>> = mutableListOf()
  while (s.hasNext()) {
    map.add(s.next().toList().map { it == '#' })
  }

  var column = 0
  var r = 0
  for (i in map.indices) {
    if (map[i][column % map[i].size]) {
      r++
    }
    column += 3
  }
  println(r)
}
