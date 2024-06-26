(defun fatorial (n)
    (cond
    ((< n 0) nil)
    ((zerop n) 1)
   (t (* n (fatorial (- n 1))))))

(defun potencia (b e)
    (cond
    ((< e 0) nil)
    ((zerop e) 1)
   (t (* b (potencia b (- e 1))))))

(defun serieH (n)
    (cond
    ((< n 1) nil)
    ((eql n 1) 1)
    ((evenp n) (- (serieH (- n 1)) (/ (potencia n n) (fatorial n))))
    (t (+ (serieH (- n 1)) (/ (potencia n n) (fatorial n))))))


(defun calcular-serieH-ate-n (limite-59-segundos)
    (loop for n from 1
        while (< (get-internal-real-time) (+ *internal-time-units-per-second* limite-59-segundos))
        do (let ((resultado (serieH n)))
                (format t "n: ~d, resultado: ~a~%" n resultado))))

(calcular-serieH-ate-n 59)
