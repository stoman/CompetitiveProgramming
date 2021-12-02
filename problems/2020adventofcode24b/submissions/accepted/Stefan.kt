import java.util.*

fun neighbors(tile: Pair<Int, Int>): List<Pair<Int, Int>> =
  listOf(Pair(tile.first, tile.second - 1), Pair(tile.first + 1, tile.second - 1), Pair(tile.first + 1, tile.second),
    Pair(tile.first - 1, tile.second), Pair(tile.first - 1, tile.second + 1), Pair(tile.first, tile.second + 1))

fun main() {
  val s = Scanner(System.`in`)
  val tiles = mutableMapOf<Pair<Int, Int>, Boolean>()
  while (s.hasNext()) {
    var x = 0
    var y = 0
    val i = s.next().iterator()
    while (i.hasNext()) {
      when (i.nextChar()) {
        'e' -> x++
        'w' -> x--
        'n' -> {
          y++
          if (i.nextChar() == 'w') {
            x--
          }
        }
        's' -> {
          y--
          if (i.nextChar() == 'e') {
            x++
          }
        }
      }
    }
    tiles[Pair(x, y)] = !(tiles[Pair(x, y)] ?: false)
  }
  var black = tiles.filter { it.value }.keys

  repeat(100) {
    val tilesToConsider = black.flatMap { neighbors(it) + listOf(it) }.toSet()
    black = tilesToConsider.filter {
      val cnt = neighbors(it).count { t -> t in black }
      (it in black && (cnt == 1 || cnt == 2)) || (it !in black && cnt == 2)
    }.toSet()
  }

  println(black.size)
}
