import java.util.Scanner
import kotlin.collections.HashSet

fun main(args: Array<String>) {
  val s = Scanner(System.`in`).useDelimiter("\\n\\n")

  val sRules = Scanner(s.next()).useDelimiter("\\n")
  val rules = mutableMapOf<Int, Set<List<String>>>()
  while(sRules.hasNext()) {
    val rule = sRules.next().split(":")
    rules[rule[0].toInt()] = rule[1].split("|").map { it.trim().split(" ") }.toSet()
  }
  val strings: HashSet<String> = rules[0]!!.flatMap { expand(it, rules) }.toHashSet()

  val sMessages = Scanner(s.next())
  var r = 0
  while (sMessages.hasNext()) {
    if(sMessages.next() in strings) {
      r++
    }
  }
  println(r)
}

fun expand(message: List<String>, rules: Map<Int, Set<List<String>>>): List<String> {
  if(message.isEmpty()) {
    return listOf("")
  }
  val next = expand(message.drop(1), rules)
  if(message.first().first() == '"') {
    return next.map { message.first().drop(1).dropLast(1) + it }
  }
  val rule = message.first().toInt()
  val firstPart = rules[rule]!!.flatMap {expand(it, rules)}
  return next.flatMap { firstPart.map { f -> f + it } }
}
