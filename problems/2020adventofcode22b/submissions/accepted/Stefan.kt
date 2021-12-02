import java.util.*

fun main() {
  val s = Scanner(System.`in`)
  var deckA: ArrayDeque<Int> = ArrayDeque()
  var deckB: ArrayDeque<Int> = ArrayDeque()
  while (s.hasNext()) {
    when (val next = s.next()) {
      "Player" -> {
        deckA = deckB
        deckB = ArrayDeque()
        s.next()
      }
      else -> deckB.addLast(next.toInt())
    }
  }

  val winningDeck = if (play(deckA, deckB) == 0) deckA else deckB
  var score = 0
  while (winningDeck.isNotEmpty()) {
    score += winningDeck.size * winningDeck.removeFirst()
  }
  println(score)
}

data class Key(val deckA: List<Int>, val deckB: List<Int>)

fun play(deckA: ArrayDeque<Int>, deckB: ArrayDeque<Int>): Int {
  val seen = mutableSetOf<Key>()

  while (deckA.isNotEmpty() && deckB.isNotEmpty()) {
    val nextA = deckA.removeFirst()
    val nextB = deckB.removeFirst()
    val key = Key(deckA.toCollection(mutableListOf()), deckB.toCollection(mutableListOf()))
    if (key in seen) {
      return 0
    }
    seen.add(key)

    val winner = if (deckA.size >= nextA && deckB.size >= nextB) {
      play(ArrayDeque(deckA.take(nextA)), ArrayDeque(deckB.take(nextB)))
    } else {
      if (nextA > nextB) 0 else 1
    }
    if (winner == 0) {
      deckA.addLast(nextA)
      deckA.addLast(nextB)
    } else {
      deckB.addLast(nextB)
      deckB.addLast(nextA)
    }
  }
  return if (deckA.isNotEmpty()) 0 else 1
}
