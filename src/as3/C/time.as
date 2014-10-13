/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.time
{

    /**
     * @name <code>&lt;time.h&gt;</code>
     * Time types.
     *
     * <p>
     * Defines time handling functions.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/time.h.html time.h
     */
    
    /** @internal */
    [native(cls="::avmshell::CTimeClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __time
    {
        public native static function get CLOCKS_PER_SEC():int;

    }

    /**
     * The number of processor clocks per second.
     * 
     * <p>
     * A number used to convert the value returned by the <code>clock()</code> function into seconds.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const CLOCKS_PER_SEC:int = __time.CLOCKS_PER_SEC;
    
    //CLOCK_MONOTONIC
    //CLOCK_PROCESS_CPUTIME_ID
    //CLOCK_REALTIME
    //CLOCK_THREAD_CPUTIME_ID
    //TIMER_ABSTIME
    
    //daylight
    //timezone
    //tzname

    //asctime()
    //asctime_r()
    //clock()
    //clock_getcpuclockid()
    //clock_getres()
    //clock_gettime()
    //clock_nanosleep()
    //clock_settime()
    //ctime()
    //ctime_r()
    //difftime()
    //getdate()
    //gmtime()
    //gmtime_r()
    //localtime()
    //localtime_r()
    //mktime()
    //nanosleep()
    //strftime()
    //strftime_l()
    //strptime()
    //time()
    //timer_create()
    //timer_delete()
    //timer_getoverrun()
    //timer_gettime()
    //timer_settime()
    //tzset()
    

    //tm
    //[native(cls="::avmshell::CtmClass", instance="::avmshell::CtmObject", methods="auto")]
    public class tm
    {

        /**
         * Construct a <code>tm</code> structure.
         */
        public function tm():void
        {

        }

        /**
         * Seconds [0,60].
         */
        public var tm_sec:int;

        /**
         * Minutes [0,59]. 
         */
        public var tm_min:int;

        /**
         * Hour [0,23].
         */
        public var tm_hour:int;

        /**
         * Day of month [1,31]. 
         */
        public var tm_mday:int;

        /**
         * Month of year [0,11]. 
         */
        public var tm_mon:int;

        /**
         * Years since 1900.
         */
        public var tm_year:int;

        /**
         * Day of week [0,6] (Sunday =0).
         */
        public var tm_wday:int;

        /**
         * Day of year [0,365].
         */
        public var tm_yday:int;

        /**
         * Daylight Savings flag.
         */
        public var tm_isdst:int;
    }

    //timespec
    //[native(cls="::avmshell::CtimespecClass", instance="::avmshell::CtimespecObject", methods="auto")]
    public class timespec
    {

        /**
         * Construct a <code>timespec</code> structure.
         */
        public function timespec( tv_sec:int = 0, tv_nsec:Number = 0 ):void
        {
            this.tv_sec  = tv_sec;
            this.tv_nsec = tv_nsec;
        }

        /**
         * Seconds.
         */
        public var tv_sec:int; //time_t

        /**
         * Nanoseconds.
         */
        public var tv_nsec:Number;
    }

    //itimerspec
    //[native(cls="::avmshell::CitimerspecClass", instance="::avmshell::CitimerspecObject", methods="auto")]
    public class itimerspec
    {

        /**
         * Construct a <code>itimerspec</code> structure.
         */
        public function itimerspec( it_interval:timespec = null, it_value:timespec = null ):void
        {
            if( !it_interval )
            {
                it_interval = new timespec();
            }

            if( !it_value )
            {
                it_value = new timespec();
            }

            this.it_interval = it_interval;
            this.it_value    = it_value;
        }

        /**
         * Timer period.
         */
        public var it_interval:timespec;

        /**
         * Timer expiration.
         */
        public var it_value:timespec;
    }


    /**
     * @private
     * only here for asdocs
     */
    [Inspectable(environment="none")]
    internal function dummy():void
    {
        //do nothing
    }
    
}