import java.util.*

fun main() {
  val s = Scanner(System.`in`).useDelimiter("\\n")
  var possibleCandidates = mutableMapOf<String, Set<String>>()
  val namesCount = mutableMapOf<String, Int>()
  while (s.hasNext()) {
    val sLine = Scanner(s.next()).useDelimiter("""\s\(|\)|,\s|\s""")
    val names = mutableListOf<String>()
    var firstPart = true
    while (sLine.hasNext()) {
      val next = sLine.next()
      when {
        next == "contains" -> {
          firstPart = false
        }
        firstPart -> {
          names += next
          namesCount[next] = 1 + (namesCount[next] ?: 0)
        }
        else -> {
          possibleCandidates[next] = names.intersect(possibleCandidates[next] ?: names)
        }
      }
    }
  }
  while (true) {
    val elim: String = possibleCandidates.filter { it.value.size == 1 }.keys.firstOrNull() ?: break
    val name = possibleCandidates[elim]!!.first()
    possibleCandidates = possibleCandidates.mapValues { it.value.minus(name) }.toMutableMap()
    namesCount.remove(name)
    possibleCandidates.remove(elim)
  }

  println(namesCount.values.sum())
}
