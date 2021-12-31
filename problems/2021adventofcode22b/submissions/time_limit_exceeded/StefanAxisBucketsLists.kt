import java.util.*

data class Instruction(
  val on: Boolean,
  val xMin: Int,
  val xMax: Int,
  val yMin: Int,
  val yMax: Int,
  val zMin: Int,
  val zMax: Int
)

fun List<Int>.distToNext(i: Int): Long = if(i + 1 >= size) 0 else (get(i + 1) - get(i)).toLong()

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`).useDelimiter("""\sx=|\.\.|,y=|,z=|\n""")
  val instructions = buildList {
    while (s.hasNext()) {
      add(Instruction(s.next() == "on", s.nextInt(), s.nextInt(), s.nextInt(), s.nextInt(), s.nextInt(), s.nextInt()))
    }
  }
  val xValues = (instructions.map { it.xMin } + instructions.map { it.xMax + 1 }).toSet().sorted()
  val yValues = (instructions.map { it.yMin } + instructions.map { it.yMax + 1 }).toSet().sorted()
  val zValues = (instructions.map { it.zMin } + instructions.map { it.zMax + 1 }).toSet().sorted()
  val xIndex = xValues.mapIndexed {i, v -> v to i}.toMap()
  val yIndex = yValues.mapIndexed {i, v -> v to i}.toMap()
  val zIndex = zValues.mapIndexed {i, v -> v to i}.toMap()
  val status = List(xValues.size) { List(yValues.size) { MutableList(zValues.size) { false } } }
  for (instruction in instructions) {
    for (x in xIndex[instruction.xMin]!! until xIndex[instruction.xMax+1]!!) {
      for (y in yIndex[instruction.yMin]!! until yIndex[instruction.yMax+1]!!) {
        for (z in zIndex[instruction.zMin]!! until zIndex[instruction.zMax+1]!!) {
          status[x][y][z] = instruction.on
        }
      }
    }
  }

  var sum = 0L
  for (x in status.indices) {
    val xDist = xValues.distToNext(x)
    for (y in status[x].indices) {
      val yDist = yValues.distToNext(y)
      for (z in status[x][y].indices) {
        if (status[x][y][z]) {
          val zDist = zValues.distToNext(z)
          sum += xDist * yDist * zDist
        }
      }
    }
  }
  println(sum)
}

