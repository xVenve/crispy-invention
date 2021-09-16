(defclass RECETA (is-a USER)
  (slot id (type SYMBOL))
  (multislot ingredientes (type SYMBOL))
  (slot num-ing (type INTEGER)))

(defclass PETICION (is-a USER)
  (multislot ingredientes (type SYMBOL))
  (slot num-ing (type INTEGER)))

(definstances ini
  (of RECETA (id r1) (ingredientes i1 i2 i3) (num-ing 3))
  (of RECETA (id r2) (ingredientes i1 i2 i4 i5) (num-ing 4))
  (of RECETA (id r3) (ingredientes i1) (num-ing 1))
  (of PETICION (ingredientes i1 i3 i4) (num-ing 3))
  )

(defrule inicializa-contadores
  (declare (salience 100))
  (object (is-a RECETA) (id ?r))
  =>
  (assert (contador-ingredientes ?r 0)))

(defrule cuenta-ingredientes-peticion
  (object (is-a PETICION) (ingredientes $? ?i $?))
  (object (is-a RECETA) (id ?r) (ingredientes $? ?i $?))
  ?cont <- (contador-ingredientes ?r ?c)
  (not (contado ?r ?i))
  =>
  (assert (contado ?r ?i))
  (retract ?cont)
  (assert (contador-ingredientes ?r (+ 1 ?c)))
  )