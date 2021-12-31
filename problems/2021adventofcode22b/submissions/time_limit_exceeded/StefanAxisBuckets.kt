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

fun List<Int>.distToNext(i: Int): Long = (get(i + 1) - get(i)).toLong()

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
  val status = mutableMapOf<Triple<Int, Int, Int>, Boolean>()
  for (instruction in instructions) {
    for (x in xIndex[instruction.xMin]!! until xIndex[instruction.xMax+1]!!) {
      for (y in yIndex[instruction.yMin]!! until yIndex[instruction.yMax+1]!!) {
        for (z in zIndex[instruction.zMin]!! until zIndex[instruction.zMax+1]!!) {
          status[Triple(x, y, z)] = instruction.on
        }
      }
    }
  }
  println(status.filterValues { it }
    .map { xValues.distToNext(it.key.first) * yValues.distToNext(it.key.second) * zValues.distToNext(it.key.third) }
    .sum())
}

