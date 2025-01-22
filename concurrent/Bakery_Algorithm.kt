package concurrent

import concurrent.StaticVar.Companion.COUNT
import concurrent.StaticVar.Companion.NUM_LOOP
import concurrent.StaticVar.Companion.NUM_THREADS
import java.util.*
import java.util.concurrent.Executors
import kotlin.collections.ArrayList
import kotlin.concurrent.Volatile

class StaticVar {
    companion object {
        const val NUM_THREADS = 4
        const val NUM_LOOP = 100
        @Volatile
        var COUNT = 0
    }
}

fun MutableList<Int>.fillWithZeros(size: Int) {
    repeat(size) {
        this.add(0)
    }
}

fun MutableList<Boolean>.fillWithFalse(size: Int) {
    repeat(size) {
        this.add(false)
    }
}

class BakeryLock {
    @Volatile
    private var entering = mutableListOf<Boolean>()
    @Volatile
    private var tickets = mutableListOf<Int>()

    init {
        entering.fillWithFalse(NUM_THREADS)
        tickets.fillWithZeros(NUM_THREADS)
    }

    fun lock(idx: Int) {
        entering[idx] = true

        val maxVal = tickets.max()

        val ticket = maxVal + 1
        tickets[idx] = ticket

        entering[idx] = false

        for(i in 0..<NUM_THREADS) {
            if(i == idx)
                continue

            while(entering[i]) { }

            while(tickets[i] != 0 && (ticket > tickets[i] || (ticket == tickets[i] && idx > i))) { }
        }
    }

    fun unlock(id: Int) {
        tickets[id] = 0
    }
}

fun main() {
    val bakery = mutableListOf<BakeryLock>()

    Runnable {
        for(i in 0..<NUM_THREADS) {
            bakery.add(BakeryLock())
            repeat(NUM_LOOP) {
                bakery[i].lock(i)
                COUNT += 1
                println("Thread = {$i} counter = {$COUNT}")
                bakery[i].unlock(i)
            }
        }
    }.run()

    Thread.sleep(10000)
}
