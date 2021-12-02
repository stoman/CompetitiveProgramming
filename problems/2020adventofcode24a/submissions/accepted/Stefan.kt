import java.util.*

fun main() {
  val s = Scanner(System.`in`)
  val tiles = mutableMapOf<Pair<Int, Int>, Boolean>()
  while(s.hasNext()) {
    var x = 0
    var y= 0
    val i = s.next().iterator()
    while(i.hasNext()) {
      when(i.nextChar()) {
        'e' -> x++
        'w' -> x--
        'n' -> {
          y++
          if(i.nextChar() == 'w') {
            x--
          }
        }
        's' -> {
          y--
          if(i.nextChar() == 'e') {
            x++
          }
        }
      }
    }
    tiles[Pair(x, y)] = !(tiles[Pair(x, y)] ?: false)
  }
  println(tiles.values.count { it })
}
