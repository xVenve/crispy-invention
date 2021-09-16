; Define la plantilla para la jarra
(deftemplate jarra
	(slot litros
		(type INTEGER)
		(default 0)))
		
(deffacts hecho-inicial
	(jarra (litros 0))
)
	
;; Inicializa la base de hechos
;; (defrule estado-inicial
;;
;; 	=>
;;	(assert (jarra))
;; )

;; Añade un litro
(defrule un-litro-mas
	?jarra <- (jarra (litros ?l))
	=>
	(modify ?jarra (litros (+ ?l 1)))
)

;; Añade dos litros
(defrule dos-litros-mas
	?jarra <- (jarra (litros ?l))	
	=>
	(modify ?jarra (litros (+ ?l 2)))
)

;; Comprueba terminacion
(defrule acabar
	(declare (salience 1000))
	(jarra (litros 3))
	=>
	(printout t "Lo he conseguido" crlf)
	(halt) ;; Otra alternativa es borrar la jarra
)
