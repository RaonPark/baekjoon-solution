package concurrent

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

data class Room(val t: Int, val a: Long, val h: Long)

class DragonAndDungeon {
    fun solve(rooms: MutableList<Room>, n: Int, atk: Long) {
        // 우선 최대 생명력을 정할 건데, t = 1 인 경우의 공격력의 최대치 * (용의 체력 / 용사의 공격력 - 1) + 1을 최대로 잡아야한다.
        var lo = 0L; var hi = Long.MAX_VALUE
        var ans = Long.MAX_VALUE

        while(lo <= hi) {
            // 미드를 먼저 정하고
            // 그 다음에 되는지 시뮬레이션
            // 만약 체력이 충분하다면 left search
            // 체력이 부족하다면 right search
            val maxHp = lo + (hi - lo) / 2L

            if(simulate(rooms, n, atk, maxHp)) {
                hi = maxHp - 1
                ans = min(ans, maxHp)
            } else {
                lo = maxHp + 1
            }
        }

        println(ans)
    }

    fun simulate(rooms: MutableList<Room>, n: Int, atk: Long, maxHp: Long): Boolean {
        var curHp = maxHp
        var curAtk = atk
        for(idx in 0..<n) {
            if(rooms[idx].t == 1) {
                val dragonAtk = rooms[idx].a
                val dragonHp = rooms[idx].h
                val atkToBeat = if(dragonHp % curAtk == 0L) dragonHp / curAtk else dragonHp / curAtk + 1
                val hits = dragonAtk * (atkToBeat - 1)

//                println("maxHp: $maxHp = ($curHp, $curAtk) $atkToBeat and $hits")

                if(hits >= curHp)
                    return false

                curHp -= hits
            } else {
                curAtk += rooms[idx].a
                curHp = min(curHp + rooms[idx].h, maxHp)
            }
        }

        return true
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (n, atk) = readLine().split(" ").map { it.toInt() }

    val rooms = mutableListOf<Room>()
    repeat(n) {
        val room = readLine().split(" ").map { it.toLong() }.toMutableList()
        val data = Room(room[0].toInt(), room[1], room[2])
        rooms.add(data)
    }

    val obj = DragonAndDungeon()
    obj.solve(rooms, n, atk.toLong())
}
