import java.util.*

const val cycles = 6

fun main() {
  val s = Scanner(System.`in`)

  val input = mutableListOf<List<Boolean>>()
  while (s.hasNext()) {
    input.add(s.next().map { it == '#' })
  }

  var map = List(1 + 2 * cycles) {
    List(1 + 2 * cycles) {
      List(input.size + 2 * cycles) {
        MutableList(input[0].size + 2 * cycles) { false }
      }
    }
  }
  for (i in input.indices) {
    for (j in input[i].indices) {
      map[cycles][cycles][i + cycles][j + cycles] = input[i][j]
    }
  }

  for (i in 1..cycles) {
    val newMap =
      List(map.size) { List(map[0].size) { List(map[0][0].size) { MutableList(map[0][0][0].size) { false } } } }
    for (a in map.indices) {
      for (b in map[a].indices) {
        for (c in map[a][b].indices) {
          for (d in map[a][b][c].indices) {
            var neighbors = if (map[a][b][c][d]) -1 else 0
            for (x in -1..1) {
              for (y in -1..1) {
                for (z in -1..1) {
                  for (q in -1..1) {
                    if (a + x in map.indices
                      && b + y in map[a + x].indices
                      && c + z in map[a + x][b + y].indices
                      && d + q in map[a + x][b + y][c + z].indices
                      && map[a + x][b + y][c + z][d + q]) {
                      neighbors++
                    }
                  }
                }
              }
            }
            newMap[a][b][c][d] = (map[a][b][c][d] && neighbors in setOf(2, 3)) || (!map[a][b][c][d] && neighbors == 3)
          }
        }
      }
    }
    map = newMap
  }
  println(map.flatten().flatten().flatten().count { it })
}
