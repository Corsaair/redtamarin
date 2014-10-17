/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{
	import C.unistd.*;
	import shell.Runtime;

    /**
     * The OperatingSystem class provide informations about the Operating System.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::OperatingSystemClass", methods="auto", construct="none")]
	public class OperatingSystem
	{

		private static var _hostname:String;

		private static var _vendor:String;


		/* NOTE:
           How can I reliably get the operating system's name?
		   http://unix.stackexchange.com/questions/92199/how-can-i-reliably-get-the-operating-systems-name

		   Detecting Underlying Linux Distro
		   http://www.novell.com/coolsolutions/feature/11251.html

		   scenario:
		   if found lsb_release
		     run "lsb_release -a"
		   else if file exists /etc/issue
		     read /etc/issue
		   else
		     loop trough _linuxDistros
		     check if the associated file exists
		
		*/
		private static var _linuxDistros:Array = [];
						   _linuxDistros[ 0] = { name: "Novell SUSE",   file: "/etc/SUSE-release" };
						   _linuxDistros[ 1] = { name: "openSUSE",      file: "/etc/SuSE-release" };
						   _linuxDistros[ 2] = { name: "Red Hat",       file: "/etc/redhat-release" };
						   _linuxDistros[ 3] = { name: "Red Hat",       file: "/etc/redhat_version" };
						   _linuxDistros[ 4] = { name: "Fedora",        file: "/etc/fedora-release" };
						   _linuxDistros[ 5] = { name: "Slackware",     file: "/etc/slackware-release" };
						   _linuxDistros[ 6] = { name: "Slackware",     file: "/etc/slackware-version" };
						   _linuxDistros[ 7] = { name: "Debian",        file: "/etc/debian_release" };
						   _linuxDistros[ 8] = { name: "Debian",        file: "/etc/debian_version" };
						   _linuxDistros[ 9] = { name: "Mandrake",      file: "/etc/mandrake-release" };
						   _linuxDistros[10] = { name: "Yellow dog",    file: "/etc/yellowdog-release" };
						   _linuxDistros[11] = { name: "Sun JDS",       file: "/etc/sun-release" };
						   _linuxDistros[12] = { name: "Solaris/Sparc", file: "/etc/release" };
						   _linuxDistros[13] = { name: "Gentoo",        file: "/etc/gentoo-release" };
						   _linuxDistros[14] = { name: "UnitedLinux",   file: "/etc/UnitedLinux-release" };
						   _linuxDistros[15] = { name: "Ubuntu",        file: "/etc/lsb-release" };
						   /*
						   _linuxDistros[16] = { name: "check origin",  file: "/etc/mandriva-release" };
						   _linuxDistros[17] = { name: "check origin",  file: "/etc/arch-release" };
						   _linuxDistros[18] = { name: "check origin",  file: "/etc/oracle-release" };
						   _linuxDistros[19] = { name: "check origin",  file: "/etc/enterprise-release" };
						   _linuxDistros[20] = { name: "check origin",  file: "/etc/ovs-release" };
						   _linuxDistros[21] = { name: "check origin",  file: "/etc/vmware-release" };
						   _linuxDistros[22] = { name: "check origin",  file: "/etc/bluewhite64-version" };
						   _linuxDistros[23] = { name: "check origin",  file: "/etc/slamd64-version" };
						   _linuxDistros[24] = { name: "check origin",  file: "/etc/alpine-release" };
						   _linuxDistros[25] = { name: "check origin",  file: "/etc/system-release" };
						   _linuxDistros[26] = { name: "check origin",  file: "/etc/centos-release" };
						   */


        private static function getVendorAll():String
        {
        	var platform:String = Runtime.platform;

            switch( platform )
            {
                case "linux":
                return "(Distro)"; //temporary, should be: Ubuntu, Debian, CentOS, etc.

                case "macintosh":
                return "Apple";
                
                case "windows":
                return "Microsoft";

                default:
                return "Unknown";
            }
        }


		/**
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public native static function isWindowsStore():Boolean;


        /**
         * The host name of the local computer.
         * 
         * @productversion redtamarin 0.3
         * @since 0.3.0
         */
        public static function get hostname():String
        {
            if( _hostname ) { return _hostname; }

            _hostname = gethostname(); //C.unistd.gethostname()
            return _hostname;
        }

        /**
         * Name of the vendor (commercial) or distributor (non-commercial) of this OS.
         * 
         * @productversion redtamarin 0.3
         * @since 0.3.0
         */
        public static function get vendor():String
        {
            if( _vendor ) { return _vendor; }

            _vendor = getVendorAll();
            return _vendor;
        }

	}

}
