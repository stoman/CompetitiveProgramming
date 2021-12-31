import java.util.*

data class Cube(val xMin: Int, val xMax: Int, val yMin: Int, val yMax: Int, val zMin: Int, val zMax: Int) {
  fun size(): Long = (xMax - xMin + 1).toLong() * (yMax - yMin + 1) * (zMax - zMin + 1)
  private fun isValid(): Boolean = xMin <= xMax && yMin <= yMax && zMin <= zMax
  fun remove(cube: Cube): Set<Cube> =
    listOf(
      Cube((cube.xMax + 1).coerceAtLeast(xMin), xMax, yMin, yMax, zMin, zMax),
      Cube(xMin, (cube.xMin - 1).coerceAtMost(xMax), yMin, yMax, zMin, zMax),
      Cube(
        cube.xMin.coerceAtLeast(xMin),
        cube.xMax.coerceAtMost(xMax),
        (cube.yMax + 1).coerceAtLeast(yMin),
        yMax,
        zMin,
        zMax
      ),
      Cube(
        cube.xMin.coerceAtLeast(xMin),
        cube.xMax.coerceAtMost(xMax),
        yMin,
        (cube.yMin - 1).coerceAtMost(yMax),
        zMin,
        zMax
      ),
      Cube(
        cube.xMin.coerceAtLeast(xMin),
        cube.xMax.coerceAtMost(xMax),
        cube.yMin.coerceAtLeast(yMin),
        cube.yMax.coerceAtMost(yMax),
        (cube.zMax + 1).coerceAtLeast(zMin),
        zMax
      ),
      Cube(
        cube.xMin.coerceAtLeast(xMin),
        cube.xMax.coerceAtMost(xMax),
        cube.yMin.coerceAtLeast(yMin),
        cube.yMax.coerceAtMost(yMax),
        zMin,
        (cube.zMin - 1).coerceAtMost(zMax)
      ),
    ).filter { it.isValid() }.toSet()
}

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`).useDelimiter("""\sx=|\.\.|,y=|,z=|\n""")
  var cubes = listOf<Cube>()
  while (s.hasNext()) {
    val on = s.next() == "on"
    val nextCube = Cube(s.nextInt(), s.nextInt(), s.nextInt(), s.nextInt(), s.nextInt(), s.nextInt())
    cubes = cubes.flatMap { it.remove(nextCube) } + if (on) listOf(nextCube) else listOf()
  }
  println(cubes.sumOf { it.size() })
}
