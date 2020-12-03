import java.util.*

fun count(map: List<List<Boolean>>, right: Int, down: Int): Int {
  var column = 0
  var r = 0
  for (i in map.indices step down) {
    if (map[i][column % map[i].size]) {
      r++
    }
    column += right
  }
  return r
}

fun main(args: Array<String>) {
  val s = Scanner(System.`in`)

  val mutableMap: MutableList<List<Boolean>> = mutableListOf()
  while (s.hasNext()) {
    mutableMap.add(s.next().toList().map { it == '#' })
  }
  var map: List<List<Boolean>> = mutableMap.toList()

  println(count(map, 1, 1) * count(map, 3, 1) * count(map, 5, 1) * count(map, 7, 1) * count(map, 1, 2))
}
