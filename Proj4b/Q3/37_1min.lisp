(defun fibonacci (n)
    (cond
    ((< n 1) nil)
    ((< n 3) 1)
    (t (+ (fibonacci (- n 1)) (fibonacci (- n 2))))))

(defun produto (n)
    (cond
    ((< n 1) nil)
    ((< n 3) 1)
   (t (* (fibonacci n) (produto (- n 1))))))


(defun calcular-produto-ate-n (limite-59-segundos)
    (loop for n from 1
        while (< (get-internal-real-time) (+ *internal-time-units-per-second* limite-59-segundos))
        do (let ((resultado (produto n)))
                (format t "n: ~d, resultado: ~a~%" n resultado))))

(calcular-produto-ate-n 59)
