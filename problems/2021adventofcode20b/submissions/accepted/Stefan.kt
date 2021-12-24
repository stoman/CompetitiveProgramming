import java.util.*

@ExperimentalStdlibApi
fun main() {
    val neighbors = listOf(
        Pair(-1, -1),
        Pair(-1, 0),
        Pair(-1, 1),
        Pair(0, -1),
        Pair(0, 0),
        Pair(0, 1),
        Pair(1, -1),
        Pair(1, 0),
        Pair(1, 1)
    )
    val s = Scanner(System.`in`)
    val algorithm = s.next().map { it == '#' }
    var currentMap = buildMap {
        var x = 0
        while (s.hasNext()) {
            s.next().forEachIndexed { y, c -> put(Pair(x, y), c == '#') }
            x++
        }
    }
    var mapDefault = false

    repeat(50) {
        currentMap = buildMap {
            for (x in currentMap.keys.minOf { it.first } - 1..currentMap.keys.maxOf { it.first } + 1) {
                for (y in currentMap.keys.minOf { it.second } - 1..currentMap.keys.maxOf { it.second } + 1) {
                    var index = 0
                    for (n in neighbors) {
                        index *= 2
                        index += if (currentMap.getOrDefault(Pair(x + n.first, y + n.second), mapDefault)) 1 else 0
                    }
                    put(Pair(x, y), algorithm[index])
                }
            }
        }
        mapDefault = if (mapDefault) algorithm.last() else algorithm.first()
    }

    println(currentMap.count { it.value })
}
