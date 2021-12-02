import java.util.*

fun main() {
  val s = Scanner(System.`in`)
  val decks = mutableMapOf<Int, Queue<Int>>()
  var id = 0
  var deck: Queue<Int> = LinkedList()
  while (s.hasNext()) {
    when (val next = s.next()) {
      "Player" -> {
        if (id > 0) decks[id] = deck
        deck = LinkedList()
        id = s.next().dropLast(1).toInt()
      }
      else -> deck.add(next.toInt())
    }
  }
  decks[id] = deck

  while (decks.values.count { it.isNotEmpty() } > 1) {
    val nextCards = decks.mapValues { it.value.remove() }
    val winner = nextCards.maxByOrNull { it.value }!!.key
    decks[winner]!!.addAll(nextCards.values.sortedDescending())
  }

  val winningDeck = decks.values.first() { it.isNotEmpty() }
  var score = 0
  while (winningDeck.isNotEmpty()) {
    score += winningDeck.size * winningDeck.remove()
  }
  println(score)
}
