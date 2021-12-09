import java.util.*

private fun computeScore(input: String): Int {
  val brackets = mapOf('(' to ')', '[' to ']', '{' to '}', '<' to '>')
  val scores = mapOf(')' to 3, ']' to 57, '}' to 1197, '>' to 25137)
  val stack = ArrayDeque<Char>()
  for (c in input) {
    when (c) {
      in brackets.keys -> stack.addFirst(c)
      brackets[stack.first] -> stack.removeFirst()
      else -> return scores[c]!!
    }
  }
  return 0
}

fun main() {
  var score = 0
  val s = Scanner(System.`in`)
  while (s.hasNext()) {
    score += computeScore(s.next())
  }
  println(score)
}
