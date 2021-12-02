import java.util.*

fun main() {
  val s = Scanner(System.`in`).useDelimiter("\\n\\n")

  val sRules = Scanner(s.next()).useDelimiter("\\n")
  val rules = mutableMapOf<Int, Set<List<String>>>()
  while (sRules.hasNext()) {
    val rule = sRules.next().split(":")
    rules[rule[0].toInt()] = rule[1].split("|").map { it.trim().split(" ") }.toSet()
  }
  val thirtyOne: HashSet<String> = rules[31]!!.flatMap { expand(it, rules) }.toHashSet()
  val fortyTwo: HashSet<String> = rules[42]!!.flatMap { expand(it, rules) }.toHashSet()

  val sMessages = Scanner(s.next())
  var r = 0
  while (sMessages.hasNext()) {
    if (check(sMessages.next(), thirtyOne, fortyTwo)) {
      r++
    }
  }
  println(r)
}

fun check(message: String, thirtyOne: HashSet<String>, fortyTwo: HashSet<String>): Boolean {
  val fortyTwoLength = fortyTwo.first().length
  val thirtyOneLength = thirtyOne.first().length

  if (message.slice(0 until fortyTwoLength) !in fortyTwo) {
    return false
  }
  for (countFortyTwo in 2..(message.length / fortyTwoLength)) {
    if (message.slice((countFortyTwo - 1) * fortyTwoLength until countFortyTwo * fortyTwoLength) !in fortyTwo) {
      return false
    }
    if ((message.length - countFortyTwo * fortyTwoLength) % thirtyOneLength == 0) {
      val countThirtyOne = (message.length - countFortyTwo * fortyTwoLength) / thirtyOneLength
      if (countThirtyOne in 1 until countFortyTwo) {
        if ((0 until countThirtyOne).all {
            message.slice(
              countFortyTwo * fortyTwoLength + it * thirtyOneLength until countFortyTwo * fortyTwoLength + (it + 1) * thirtyOneLength) in thirtyOne
          }) {
          return true
        }
      }
    }
  }
  return false
}

fun expand(message: List<String>, rules: Map<Int, Set<List<String>>>): List<String> {
  if (message.isEmpty()) {
    return listOf("")
  }
  val next = expand(message.drop(1), rules)
  if (message.first().first() == '"') {
    return next.map { message.first().drop(1).dropLast(1) + it }
  }
  val rule = message.first().toInt()
  val firstPart = rules[rule]!!.flatMap { expand(it, rules) }
  return next.flatMap { firstPart.map { f -> f + it } }
}
