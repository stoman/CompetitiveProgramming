import java.util.*

private data class Node(val name: String) {
  fun canBeVisitedMultipleTimes(): Boolean = name.first().isUpperCase()
}

private data class PathStatus(val current: Node, val visited: Set<Node>, val visitedSmallCaveTwice: Boolean)

fun main() {
  val s = Scanner(System.`in`).useDelimiter("""[\n-]""")
  val connections = mutableMapOf<Node, Set<Node>>()
  while (s.hasNext()) {
    val a = Node(s.next())
    val b = Node(s.next())
    connections[a] = connections.getOrDefault(a, setOf()) + b
    connections[b] = connections.getOrDefault(b, setOf()) + a
  }

  val queue = ArrayDeque<PathStatus>()
  var pathsToEnd = 0
  val startStatus = PathStatus(Node("start"), setOf(Node("start")), visitedSmallCaveTwice = false)
  queue.add(startStatus)

  while (queue.isNotEmpty()) {
    val status = queue.removeFirst()
    for (next in connections.getOrDefault(status.current, setOf())) {
      if (next.canBeVisitedMultipleTimes() || next !in status.visited || (!status.visitedSmallCaveTwice && next.name != "start")) {
        val nextStatus = PathStatus(
          next,
          status.visited + next,
          status.visitedSmallCaveTwice || (next in status.visited && !next.canBeVisitedMultipleTimes())
        )
        if (next.name != "end") {
          queue.addLast(nextStatus)
        } else {
          pathsToEnd++
        }
      }
    }
  }

  println(pathsToEnd)
}
