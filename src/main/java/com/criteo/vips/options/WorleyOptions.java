/*
Copyright (c) 2022 Criteo

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

package com.criteo.vips.options;

/**
 * Optional arguments for the "worley" operation.
 */
public class WorleyOptions {

	private Integer cellSize;
	private Integer seed;

	/**
	 * Optional argument: cell-size
	 * <p>
	 * Size of Worley cells
	 * @return the value of {@code cellSize}
	 */
	public Integer getCellSize() {
		return this.cellSize;
	}

	/**
	 * Set the optional "cell-size" argument.
	 * <p>
	 * Size of Worley cells
	 * @param cellSize the new value of {@code cellSize}
	 */
	public void setCellSize(Integer cellSize) {
		this.cellSize = cellSize;
	}

	/**
	 * Set the optional "cell-size" argument.
	 * <p>
	 * Size of Worley cells
	 * @param cellSize the new value of {@code cellSize}
	 * @return this object for chaining
	 */
	public WorleyOptions cellSize(Integer cellSize) {
		setCellSize(cellSize);
		return this;
	}

	/**
	 * Optional argument: seed
	 * <p>
	 * Random number seed
	 * @return the value of {@code seed}
	 */
	public Integer getSeed() {
		return this.seed;
	}

	/**
	 * Set the optional "seed" argument.
	 * <p>
	 * Random number seed
	 * @param seed the new value of {@code seed}
	 */
	public void setSeed(Integer seed) {
		this.seed = seed;
	}

	/**
	 * Set the optional "seed" argument.
	 * <p>
	 * Random number seed
	 * @param seed the new value of {@code seed}
	 * @return this object for chaining
	 */
	public WorleyOptions seed(Integer seed) {
		setSeed(seed);
		return this;
	}

}
