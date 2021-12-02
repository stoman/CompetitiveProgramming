import java.util.Scanner

fun main() {
  val s = Scanner(System.`in`).useDelimiter(",|\\s")
  var turn = 0
  var last = -1
  val lastMentioned = mutableMapOf<Int, Int>()
  while (s.hasNext()) {
    lastMentioned[last] = turn
    last = s.nextInt()
    turn++
  }
  while(turn < 30000000) {
    val next = if(lastMentioned.containsKey(last)) turn - lastMentioned[last]!! else 0
    lastMentioned[last] = turn
    last = next
    turn++
  }
  println(last)
}
