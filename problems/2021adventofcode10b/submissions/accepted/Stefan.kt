import java.util.*

private fun computeScore(input: String): Long? {
  val brackets = mapOf('(' to ')', '[' to ']', '{' to '}', '<' to '>')
  val scores = mapOf(')' to 1, ']' to 2, '}' to 3, '>' to 4)
  val stack = ArrayDeque<Char>()
  for (c in input) {
    when (c) {
      in brackets.keys -> stack.addFirst(c)
      brackets[stack.first] -> stack.removeFirst()
      else -> return null
    }
  }

  var score = 0L
  while(stack.isNotEmpty()) {
    score *= 5
    score += scores[brackets[stack.removeFirst()]]!!
  }
  return score
}

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`)
  val scores = buildList {
    while (s.hasNext()) {
      add(computeScore(s.next()))
    }
  }
  println(scores.filterNotNull().sorted()[scores.filterNotNull().size/2])
}
