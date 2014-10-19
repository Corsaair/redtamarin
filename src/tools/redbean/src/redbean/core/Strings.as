package redbean.core
{
    public class Strings
    {
        public var sdk:String;
        
        public var asc:String;
        
        public var asc2:String;
        
        public var redshell:String;
        
        public var redshell_d:String;
        
        public var redshell_dd:String;
        
        public var redtamarin_abc:String;
        
        public var includeLine:String;
        
        public var platform:String;
        
        public var bits:String;
        
        public var extension:String;
        
        public function Strings()
        {
            sdk            = "";
            asc            = "";
            asc2           = "";
            redshell       = "";
            redshell_d     = "";
            redshell_dd    = "";
            redtamarin_abc = "";
            includeLine    = "";
            platform       = "";
            bits           = "";
            extension      = "";
        }
        
        public function toObject():Object
        {
            var o:Object = {};
                o.sdk            = sdk;
                o.asc            = asc;
                o.asc2           = asc2;
                o.redshell       = redshell;
                o.redshell_d     = redshell_d;
                o.redshell_dd    = redshell_dd;
                o.redtamarin_abc = redtamarin_abc;
                o.includeLine    = includeLine;
                o.platform       = platform;
                o.bits           = bits;
                o.extension      = extension;
            
            return o;
        }
        
    }
}