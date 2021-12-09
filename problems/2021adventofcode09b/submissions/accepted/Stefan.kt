import java.util.*

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`)
  val heightmap = buildList {
    while (s.hasNext()) {
      add(s.next().map { it.toString().toInt() })
    }
  }
  val sizes = mutableListOf<Int>()
  val visited = heightmap.map { line -> line.map { it == 9 }.toMutableList() }.toMutableList()
  for (i in heightmap.indices) {
    for (j in heightmap[i].indices) {
      if (!visited[i][j]) {
        sizes += fill(i, j, visited)
      }
    }
  }
  println(sizes.sorted().takeLast(3).reduce(Int::times))
}

private fun fill(i: Int, j: Int, visited: MutableList<MutableList<Boolean>>): Int {
  if (i !in visited.indices || j !in visited[i].indices || visited[i][j]) {
    return 0
  }
  visited[i][j] = true
  return 1 + fill(i - 1, j, visited) + fill(i + 1, j, visited) + fill(i, j - 1, visited) + fill(i, j + 1, visited)
}
