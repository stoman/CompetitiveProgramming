import java.util.*

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`)
  val heightmap = buildList {
    while (s.hasNext()) {
      add(s.next().map { it.toString().toInt() })
    }
  }
  var ret = 0
  for (i in heightmap.indices) {
    for (j in heightmap[i].indices) {
      if (i - 1 in heightmap.indices && heightmap[i][j] >= heightmap[i - 1][j]) continue
      if (i + 1 in heightmap.indices && heightmap[i][j] >= heightmap[i + 1][j]) continue
      if (j - 1 in heightmap[i].indices && heightmap[i][j] >= heightmap[i][j - 1]) continue
      if (j + 1 in heightmap[i].indices && heightmap[i][j] >= heightmap[i][j + 1]) continue
      ret += heightmap[i][j] + 1
    }
  }
  println(ret)
}
