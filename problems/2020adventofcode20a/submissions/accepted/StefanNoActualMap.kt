import java.math.BigInteger
import java.util.*

private data class Border(val chars: List<Char>) {
  override fun equals(other: Any?): Boolean {
    if (this === other) return true
    if (other?.javaClass != javaClass) return false

    other as Border
    return chars == other.chars || chars.reversed() == other.chars
  }
}

private data class Tile(val id: BigInteger, val chars: List<List<Char>>) {
  fun borders(): List<Border> {
    return listOf(Border(chars.first()), Border(chars.last()), Border(chars.map { it.first() }),
      Border(chars.map { it.last() }))
  }
}

fun main(args: Array<String>) {
  val s = Scanner(System.`in`).useDelimiter("\\n\\n")

  val tiles = mutableMapOf<BigInteger, Tile>()
  while (s.hasNext()) {
    val sTile = Scanner(s.next()).useDelimiter(""":\s|\s""")
    sTile.next() // "Tile"
    val id = sTile.nextBigInteger()
    val chars = mutableListOf<List<Char>>()
    while (sTile.hasNext()) {
      chars += sTile.next().toList()
    }
    tiles[id] = Tile(id, chars)
  }

  val borders = tiles.values.flatMap { it.borders() }
  val corners =
    tiles.values.filter { it.borders().filter { border -> borders.count { t -> t == border } == 1 }.size == 2 }
  println(corners.map { it.id }.reduce(BigInteger::times))
}
