Задание повышенной сложности.

Реализуйте класс SharedPtr как описано ранее. Задание немного сложнее, чем кажется на первый взгляд. Уделите особое внимание "граничным случаям" — 
нулевой указатель, присваивание самому себе, вызов reset на нулевом SharedPtr и прочее.

Подсказка: возможно, вам понадобится завести вспомогательную структуру.

Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.

#include <cassert>

struct Expression;
struct Number;
struct BinaryOperation;
struct FunctionCall;
struct Variable;

struct SharedPtr {
    explicit SharedPtr(Expression *ptr = 0) {
        if (ptr == 0) {
            p_cnt = 0;
        }
        else {
            p_cnt = new size_t(1);
        }
        this->ptr = ptr;
    }

    SharedPtr(const SharedPtr& other) {
        if (other.get() == 0) {
            p_cnt = 0;
        }
        else {
            p_cnt = other.get_counter();
            incr();
        }
        ptr = other.get();
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if(ptr != other.get()){
            if(ptr != 0)
                decr();
            if(other.get() != 0) {
                ptr = other.get();
                p_cnt = other.get_counter();
                incr();
            }
            else {
                ptr = 0;
                p_cnt = 0;
            }
        }
        return *this;
    }

    ~SharedPtr() {
      decr();
   }

 void reset(Expression *ptr = 0) {
     decr();
         if(ptr != 0) {
            p_cnt = new size_t(1);
            this->ptr = ptr;
        }
        else {
            this->p_cnt = 0;
            this->ptr = 0;
        }
 }

   Expression * get() const {
      if (ptr) {
         return ptr;
      }
      return 0;
   }

    size_t * get_counter() const {
         return p_cnt;
    }

   size_t count() const {
      if (ptr) {
         return *p_cnt;
      }
      return 0;
   }

   bool empty() const {
      return !get();
   }

   Expression & operator *() const {
      assert(get());
      return *get();
   }

   Expression * operator ->() const {
      assert(ptr);
      return ptr;
   }

private:
   void incr() {
      if (ptr) {
         ++*p_cnt;
      }
   }

   void decr() {
      if(ptr)
          --(*p_cnt);

      if (ptr && *p_cnt == 0) {
         delete ptr;
         ptr = 0;
         delete p_cnt;
         p_cnt = 0;
      }
   }

    Expression *ptr;
    size_t * p_cnt;
};
