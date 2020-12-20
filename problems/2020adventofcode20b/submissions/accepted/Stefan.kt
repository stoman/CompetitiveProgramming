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

fun main(args: Array<String>) {
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
  for (j in (keysSecond.min()!!)..(keysSecond.max()!!)) {
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
    for (i in (keysFirst.min()!!)..(keysFirst.max())!!) {
      for (j in map[Pair(i, 0)]!!.chars.indices) {
        println(
          ((keysSecond.min()!!)..(keysSecond.max()!!)).joinToString(" ") {
            map[Pair(i, it)]!!.chars[j].joinToString("")
          })
      }
      println()
    }
  }

  val fullMap = mutableListOf<MutableList<Char>>()
  for (i in (keysFirst.min()!!)..(keysFirst.max())!!) {
    for (j in 1 until map[Pair(i, 0)]!!.chars.size -1) {
      fullMap += ((keysSecond.min()!!)..(keysSecond.max()!!)).flatMap {
        map[Pair(i, it)]!!.chars[j].drop(1).dropLast(1)
      }.toMutableList()
    }
  }

  val monster: List<List<Char>> = listOf(
    "                  # ".toList(),
    "#    ##    ##    ###".toList(),
    " #  #  #  #  #  #   ".toList())
  for (monsterRotation in MyTile(BigInteger.ZERO, monster).allTransformations().map { it.chars }) {
    for (i in 0 until fullMap.size - monsterRotation.size) {
      for (j in 0 until fullMap[i].size - monsterRotation[0].size) {
        var found = true
        for (x in monsterRotation.indices) {
          for (y in monsterRotation[x].indices) {
            if (monsterRotation[x][y] == '#' && fullMap[x + i][y + j] !in setOf('#', 'O')) {
              found = false
            }
          }
        }
        if (found) {
          for (x in monsterRotation.indices) {
            for (y in monsterRotation[x].indices) {
              if (monsterRotation[x][y] == '#') {
                fullMap[x + i][y + j] = 'O'
              }
            }
          }
        }
      }
    }
  }

  if (DEBUG) {
    for (i in fullMap.indices) {
      println(fullMap[i].joinToString(""))
    }
  }

  println(fullMap.flatten().count { it == '#' })
}
