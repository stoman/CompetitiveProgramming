import java.lang.Integer.min
import java.util.*

@ExperimentalStdlibApi
fun main() {
    val s = Scanner(System.`in`)
    repeat(4) {s.next()}
    var posA = s.nextInt()
    var scoreA = 0
    repeat(4) {s.next()}
    var posB = s.nextInt()
    var scoreB = 0
    var rolls = 0
    while(true) {
        repeat(3) {
            rolls++
            posA = (posA + rolls) % 10
        }
        scoreA += if(posA == 0) 10 else posA
        if(scoreA >= 1000) {
            break
        }
        repeat(3) {
            rolls++
            posB = (posB + rolls) % 10
        }
        scoreB += if(posB == 0) 10 else posB
        if(scoreB >= 1000) {
            break
        }
    }

    println(min(scoreA, scoreB) * rolls)
}
