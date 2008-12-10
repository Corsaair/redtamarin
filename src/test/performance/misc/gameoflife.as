/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2008
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */
 
package{

	public class DrawGrid {

		private var rows:int =100;
		private var cols:int= 100;
		private var cells:Array = new Array(rows*cols);
		private var gen =1;
		public var k:uint=0;
		public var Iterations = 0;
		public var total =0;

		public function DrawGrid() {
			reset();
			Simulation();
		}
	    

		private function Simulation():void{
			Iterations=0;

			var generations:int=500;
			for (var i=0;i<generations;i++){
				Iterations++;

				var start2:Number = new Date();

				step();
				draw();
				var end2:Number = new Date();
				var t2 = end2-start2;
//				print("The time taken for generation: "+Iterations+" is:"+t2 +" ms"+"\n");
			}
		}

		// Resets the simulation to an initial, randomized state.
		private function reset():void {
			gen=1;
			k=k++;
			var p=new TRandom(k);

			for (var offset:int = cells.length - 1; offset >= 0; offset--) {
				var t = p.IRandom(0,1);
				cells[offset] = (t * 2 > 1.0);
			}
		}

        
		// Returns a boolean indicating whether the cell at given coordinates
		// is alive or dead. Note that cells outside the grid boundaries are
		// currently considered dead.
		private function cell (row:int, col:int):Boolean {
			return (row >= 0 && row < rows && col >= 0 && col < cols
				&& cells[row * cols + col]);
		}
       
		// Advances the simulation by a discrete time step. This is a very
		// straightforward, 'naive' implementation of the Game of Life.
		private function step():Boolean {
			var next:Array = new Array(rows * cols);
			var changed:Boolean = false;

			for (var row:int = rows - 1; row >= 0; row--) {
				var row_offset:int = row * cols;
				for (var col:int = cols - 1; col >= 0; col--) {
					var count:int= 0;
					if (cell(row - 1, col - 1)) count++;
					if (cell(row - 1, col)) count++;
					if (cell(row - 1, col + 1)) count++;
					if (cell(row, col - 1)) count++;
					if (cell(row, col + 1)) count++;
					if (cell(row + 1, col - 1)) count++;
					if (cell(row + 1, col)) count++;
					if (cell(row + 1, col + 1)) count++;
					var old_state:Boolean = cells[row_offset + col];
					var new_state:Boolean = (!old_state && count == 3)
						|| (old_state && (count == 2 || count == 3));
					
					if (!changed && new_state != old_state)
						changed = true;
						
					next[row_offset + col] = new_state;
				}
			}
			cells = next;
			return changed; // indicates if simulation is still active
		}

		private function draw():void{
			var xPos:int = 0;
			var yPos:int =0;
			var rwidth:int = 200;
			var rheight:int = 200;

			var width:Number = Math.floor(rwidth/cols);
			var height:Number = Math.floor(rheight/rows);

			//draw living cell
			for (var row:int = rows - 1; row >= 0; row--) {
				var row_offset:int = row * cols;
				for (var col:int = cols - 1; col >= 0; col--) {
					if (cells[row_offset + col]) {
						//print("The coordinates of the cell that is alive for generation: "+Iterations+" is: "+ "[" + row +","+col +"]");
					}
				}
			}
			//print("\n");


		}
	}

	class TRandom {
			public var x:Array=new Array(5);
			
			public function TRandom(seed:uint){
				RandomInit(seed);
			}
			public function Random():Number{
				var c:Number;
				c = Number(2111111111.0) * x[3] +1492.0 * (x[3] = x[2]) +1776.0 * (x[2] = x[1]) +5115.0 * (x[1] = x[0]) +x[4];
				x[4] = Math.floor(c);
				x[0] = c - x[4];
				x[4] = x[4] * (1.0/(65536.0*65536.0));
				return x[0];
			}

			public function IRandom(min:int, max:int):int{
				var iinterval:int = max - min + 1;
				if (iinterval <= 0) return 0x80000000; // error
					var i:int = int(iinterval * Random());     // truncate
				if (i >= iinterval) i = iinterval-1;

				return min + i;
			}

			public function RandomInit (seed:uint):Number {
				var i:int;
				var s:uint = seed;
				// make random numbers and put them into the buffer
				for (i=0; i<5; i++) {
					s = s * 29943829 - 1;
					x[i] = s * (1.0/(65536.0*65536.0));
				}
				// randomize some more
				for (i=0; i<19; i++){
					Random();
				} 
			}
	}
	
	
	var t:Number = new Date();
	var k = new DrawGrid();
	t = new Date() - t;
	print("metric time "+t);
}
