import java.util.*


enum class Seat { EMPTY, OCCUPIED, FLOOR }
data class WaitingArea(val seats: List<List<Seat>>) {
  private val neighbors =
    listOf(Pair(-1, -1), Pair(-1, 0), Pair(-1, 1), Pair(0, -1), Pair(0, 1), Pair(1, -1), Pair(1, 0), Pair(1, 1))

  fun people(): Int = seats.sumOf { it.count { cell -> cell == Seat.OCCUPIED } }
  fun next(): WaitingArea {
    val r = List(seats.size) { MutableList(seats[0].size) {Seat.FLOOR} }
    for (i in seats.indices) {
      for (j in seats[i].indices) {
        var peopleAround = 0
        for (n in neighbors) {
          var x = i + n.first
          var y = j + n.second
          while (x in seats.indices && y in seats[x].indices && seats[x][y] == Seat.FLOOR) {
            x += n.first
            y += n.second
          }
          if (x in seats.indices && y in seats[x].indices && seats[x][y] == Seat.OCCUPIED) {
            peopleAround++
          }
        }
        r[i][j] = when {
          seats[i][j] == Seat.EMPTY && peopleAround == 0 -> Seat.OCCUPIED
          seats[i][j] == Seat.OCCUPIED && peopleAround >= 5 -> Seat.EMPTY
          else -> seats[i][j]
        }
      }
    }
    return WaitingArea(r)
  }
}

fun main() {
  val s = Scanner(System.`in`)
  val input = mutableListOf<List<Seat>>()
  while (s.hasNext()) {
    input.add(s.next().map { if (it == 'L') Seat.EMPTY else Seat.FLOOR })
  }
  var wait = WaitingArea(input)
  var last: WaitingArea
  do {
    last = wait
    wait = wait.next()
  } while (last != wait)
  println(wait.people())
}
