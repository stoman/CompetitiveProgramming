import java.lang.Long.max
import java.util.*

data class BoardState(val scoreA: Int, val scoreB: Int, val posA: Int, val posB: Int, val nextTurnByA: Boolean) :
  Comparable<BoardState> {
  override fun compareTo(other: BoardState): Int =
    compareBy<BoardState> { it.scoreA + it.scoreB }.thenBy { it.scoreA }.thenBy { it.posA }.thenBy { it.posB }
      .thenBy { it.nextTurnByA }.compare(this, other)
}

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`)
  repeat(4) { s.next() }
  val posA = s.nextInt() % 10
  repeat(4) { s.next() }
  val posB = s.nextInt() % 10
  val start = BoardState(0, 0, posA, posB, true)

  val states = mutableMapOf(start to 1L)
  val queue = mutableSetOf(start)
  val possibleRolls = mapOf(3 to 1L, 4 to 3L, 5 to 6L, 6 to 7L, 7 to 6L, 8 to 3L, 9 to 1L)
  var winsA = 0L
  var winsB = 0L

  while (queue.isNotEmpty()) {
    val current = queue.minOrNull()!!
    queue -= current
    for ((roll, possibilities) in possibleRolls) {
      val allPossibilities = possibilities * states[current]!!
      val next = if (current.nextTurnByA) {
        val nextPos = (current.posA + roll) % 10
        current.copy(posA = nextPos, scoreA = current.scoreA + if (nextPos == 0) 10 else nextPos, nextTurnByA = false)
      } else {
        val nextPos = (current.posB + roll) % 10
        current.copy(posB = nextPos, scoreB = current.scoreB + if (nextPos == 0) 10 else nextPos, nextTurnByA = true)
      }

      if (next.scoreA >= 21) {
        winsA += allPossibilities
        continue
      }
      if (next.scoreB >= 21) {
        winsB += allPossibilities
        continue
      }
      
      states.merge(next, allPossibilities, Long::plus)
      queue += next
    }
  }

  println(max(winsA, winsB))
}
