import java.math.BigInteger
import java.util.*

const val DEBUG = false

private data class MyTile(val id: BigInteger, val chars: List<List<Char>>) {
  fun mirror(): MyTile {
    return MyTile(id, chars.reversed())
  }

  fun rotate(): MyTile {
    val r = List(chars.first().size) { MutableList(chars.size) { '?' } }
    for (i in r.indices) {
      for (j in r[i].indices) {
        r[i][j] = chars[j][chars[j].size - 1 - i]
      }
    }
    return MyTile(id, r)
  }

  fun allTransformations(): List<MyTile> {
    val r = mutableListOf(this)
    for (i in 2..4) {
      r += r.last().rotate()
    }
    r += r.map { it.mirror() }
    return r
  }

  fun fitsRight(other: MyTile): Boolean {
    for (i in chars.indices) {
      if (chars[i].last() != other.chars[i].first()) {
        return false
      }
    }
    return true
  }

  fun fitsBottom(other: MyTile): Boolean {
    for (i in chars.last().indices) {
      if (chars.last()[i] != other.chars.first()[i]) {
        return false
      }
    }
    return true
  }

  fun fitsLeft(other: MyTile): Boolean {
    for (i in chars.indices) {
      if (chars[i].first() != other.chars[i].last()) {
        return false
      }
    }
    return true
  }

  fun fitsTop(other: MyTile): Boolean {
    for (i in chars.first().indices) {
      if (chars.first()[i] != other.chars.last()[i]) {
        return false
      }
    }
    return true
  }
}

fun main() {
  val s = Scanner(System.`in`).useDelimiter("\\n\\n")

  val tiles = mutableSetOf<MyTile>()
  while (s.hasNext()) {
    val sTile = Scanner(s.next()).useDelimiter(""":\s|\s""")
    sTile.next() // "Tile"
    val id = sTile.nextBigInteger()
    val chars = mutableListOf<List<Char>>()
    while (sTile.hasNext()) {
      chars += sTile.next().toList()
    }
    tiles += MyTile(id, chars)
  }

  val map = mutableMapOf<Pair<Int, Int>, MyTile>()
  map[Pair(0, 0)] = tiles.first()
  var allTransformations: List<MyTile> = tiles.drop(1).flatMap { it.allTransformations() }

  for (j in 0 until tiles.size) {
    val next: MyTile = allTransformations.firstOrNull { it.fitsLeft(map[Pair(0, j)]!!) } ?: break
    map[Pair(0, j + 1)] = next
    allTransformations = allTransformations.filter { it.id != next.id }
  }

  for (j in 0 downTo -tiles.size) {
    val next: MyTile = allTransformations.firstOrNull { it.fitsRight(map[Pair(0, j)]!!) } ?: break
    map[Pair(0, j - 1)] = next
    allTransformations = allTransformations.filter { it.id != next.id }
  }

  val keysSecond = map.keys.map { it.second }
  for (j in (keysSecond.minOrNull()!!)..(keysSecond.maxOrNull()!!)) {
    for (i in 0 downTo -tiles.size) {
      val next: MyTile = allTransformations.firstOrNull { it.fitsBottom(map[Pair(i, j)]!!) } ?: break
      map[Pair(i - 1, j)] = next
      allTransformations = allTransformations.filter { it.id != next.id }
    }

    for (i in 0 until tiles.size) {
      val next: MyTile = allTransformations.firstOrNull { it.fitsTop(map[Pair(i, j)]!!) } ?: break
      map[Pair(i + 1, j)] = next
      allTransformations = allTransformations.filter { it.id != next.id }
    }
  }

  val keysFirst = map.keys.map { it.first }

  if (DEBUG) {
    for (i in (keysFirst.minOrNull()!!)..(keysFirst.maxOrNull())!!) {
      for (j in map[Pair(i, 0)]!!.chars.indices) {
        println(
          ((keysSecond.minOrNull()!!)..(keysSecond.maxOrNull()!!)).joinToString(" ") {
            map[Pair(i, it)]!!.chars[j].joinToString("")
          })
      }
      println()
    }
  }

  println(
    map[Pair(keysFirst.minOrNull(), keysSecond.minOrNull())]!!.id
      * map[Pair(keysFirst.minOrNull(), keysSecond.maxOrNull())]!!.id
      * map[Pair(keysFirst.maxOrNull(), keysSecond.minOrNull())]!!.id
      * map[Pair(keysFirst.maxOrNull(), keysSecond.maxOrNull())]!!.id)
}
