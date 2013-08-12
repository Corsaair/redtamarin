/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
// 9.3.1 access methods via unqualified (public) name and any
// qualified name
package QualUnqualAccess {
    interface T {
        function f();
    }
    interface U extends T {
        function g();
    }
    interface V {
        function h();
    }

    class A implements T {
        public function f() {
            return "a.T::f()";
        }
    }
    class B implements U {
        public function f() {
            return "b.T::f()";
        }
        public function g() {
            return "b.U::g()";
        }
    }
    class C implements T, V {
        public function f() {
            return "c.T::f()";
        }
        
        public function h() {
            return "c.V::h()";
        }
    }
    class D implements U, V {
        public function f() {
            return "d.T::f()";
        }
        
        public function g() {
            return "d.U::g()";
        }
        public function h() {
            return "d.V::h()";
        }
    }
    class E extends B {
        public function h() {
            return "e.E::h()";
        }
        }
    class F extends B implements V {
        public function h() {
            return "f.V::h()";
        }
    }
    
    public class AccessTest {
        var a : A = new A();
        var t : T = a;
        var b : B = new B();
        var u : U = b;
        var t1: T = b;
        var c : C = new C();
        var t2: T = c;
        var v : V = c;
        var d : D = new D();
        var u2: U = d;
        var t3: T = d;
        var v2: V = d;
        var e : E = new E();
        var t4: T = e;
        var u3: U = e;
        var f : F = new F();
        var t5: T = f;
        var u4: U = f;
        var v3: V = f;

        public function doAccessA() : String {
            return a.f() + "," + a.T::f() + "," + t.f();
        }
        public function doAccessBF() : String {
            return b.f() + "," + b.T::f() + "," + b.T::f() + "," + t1.f();
        }
        public function doAccessBG() : String {
            return b.g() + "," + b.U::g() + "," + u.g();
        }
        public function doAccessCF() : String {
            return c.f() + "," + c.T::f() + "," + t2.f();
        }
        public function doAccessCH() : String {
            return c.h() + "," + c.V::h() + "," + v.h();
        }
        public function doAccessDF() : String {
            return  u2.f() +"," + d.T::f() + "," + d.f() + "," + t3.f();
        }
        
        public function doAccessDG() : String {
            return d.g() + "," + d.U::g()+ "," + u2.g();
        }
        public function doAccessDH() : String {
            return d.h() + "," + d.V::h() + "," + v2.h();
        }
        public function doAccessEF() : String {
            return e.f() + "," + e.T::f() + "," + t4.f() + "," + u3.f() ;
        }
        
        public function doAccessEG() : String {
            return e.g() + "," + e.U::g() + "," + u3.g();
        }
        public function doAccessEH() : String {
            return e.h();
        }
        public function doAccessFF() : String {
            return f.f() + ","  + f.T::f() + "," + u4.f() + "," + t5.f() ;
        }
        
        public function doAccessFG() : String {
            return f.g() + "," + f.U::g() + "," + u4.g();
        }
        public function doAccessFH() : String {
            return f.h() + "," + f.V::h() + "," + v3.h();
        }


    }

}

